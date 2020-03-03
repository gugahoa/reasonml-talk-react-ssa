type state = Types.auth_user;

type action =
  | SetUser(Types.auth_user);

let reducer = (state, action) => {
  switch (action) {
  | SetUser(user) => user
  };
};

[@react.component]
let make = () => {
  let url = ReasonReactRouter.useUrl();
  let (state, dispatch) = React.useReducer(reducer, Types.Anonymous);

  let login = (email, password) => {
    dispatch(SetUser(LoggedIn({name: "Gustavo", email: "gustavo@kinase.med.br"})));
  };

  switch (state, url.path) {
  | (_, ["dogs"]) => <FetchedDogPictures />
  | (Anonymous, ["login"]) => <Login login />
  | (LoggedIn({name}), _)
  | (Anonymous, [name]) => <Greeter name />
  | (Anonymous, _) => <div> {React.string("Anonymous")} </div>
  };
};
