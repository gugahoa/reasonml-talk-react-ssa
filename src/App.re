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
    |> Js.Promise.then_(resp => Js.Json.decodeObject(resp) |> Belt.Option.getExn |> Js.Promise.resolve)
    |> Js.Promise.then_(resp => {
         let user = Js.Dict.get(resp, "user")->Belt.Option.flatMap(Js.Json.decodeObject) |> Belt.Option.getExn;
         let name = Js.Dict.get(user, "name")->Belt.Option.flatMap(Js.Json.decodeString) |> Belt.Option.getExn;
         let email = Js.Dict.get(user, "email")->Belt.Option.flatMap(Js.Json.decodeString) |> Belt.Option.getExn;
         dispatch(SetUser(LoggedIn({name, email})));
         () |> Js.Promise.resolve;
       })
    |> ignore;
  };

  switch (state, url.path) {
  | (_, ["dogs"]) => <FetchedDogPictures />
  | (Anonymous, ["login"]) => <Login login />
  | (LoggedIn({name}), _)
  | (Anonymous, [name]) => <Greeter name />
  | (Anonymous, _) => <div> {React.string("Anonymous")} </div>
  };
};
