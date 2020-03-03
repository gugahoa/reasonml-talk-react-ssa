type state = {
  user: Types.auth_user,
  error: option(string),
};

type action =
  | Error
  | SetUser(Types.auth_user);

let reducer = (state, action) => {
  switch (action) {
  | SetUser(user) => { error: None, user }
  | Error => { ...state, error: Some("Erro de login") }
  };
};

[@react.component]
let make = () => {
  let url = ReasonReactRouter.useUrl();
  let (state, dispatch) = React.useReducer(reducer, {user: Types.Anonymous, error: None});

  let login = (email, password) => {
    let payload = Js.Dict.empty();
    Js.Dict.set(payload, "email", Js.Json.string(email));
    Js.Dict.set(payload, "password", Js.Json.string(password));
    Fetch.fetchWithInit(
      "http://localhost:4000/api/login",
      Fetch.RequestInit.make(
        ~method_=Post,
        ~body=Fetch.BodyInit.make(Js.Json.stringify(Js.Json.object_(payload))),
        ~headers=Fetch.HeadersInit.make({"Content-Type": "application/json"}),
        (),
      ),
    )
    |> Js.Promise.then_(Fetch.Response.json)
    |> Js.Promise.then_(resp => Types.login_resp_decode(resp) |> Js.Promise.resolve)
    |> Js.Promise.then_(resp => {
        switch (resp) {
        | Ok(login_resp: Types.login_resp) => dispatch(SetUser(LoggedIn(login_resp.user)))
        | Error(_) => dispatch(Error)
        };
       () |> Js.Promise.resolve;
       })
    |> ignore;
  };

  switch (state.user, url.path) {
  | (_, ["dogs"]) => <FetchedDogPictures />
  | (Anonymous, ["login"]) => <Login login error=?state.error />
  | (LoggedIn({name}), _)
  | (Anonymous, [name]) => <Greeter name />
  | (Anonymous, _) => <div> {React.string("Anonymous")} </div>
  };
};
