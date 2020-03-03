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

  let login = () => {
    dispatch(SetUser(LoggedIn({name: "Gustavo", email: "gustavo@kinase.med.br"})));
  };

  switch (state) {
    | Anonymous =>
      switch (url.path) {
        | [name] => <Greeter name />
        | _ => <div>{React.string("Anonymous")}</div>
      }
    | LoggedIn({ name: name }) => <Greeter name />
  }
};
