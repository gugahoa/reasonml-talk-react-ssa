open Types;
type login = {user};

module LoginMutation = [%graphql
  {|
  mutation($email: String!, $password: String!) {
    login(email: $email, password: $password) @bsRecord {
      user @bsRecord {
        name
        email
      }
    }
  }
|}
];

[@react.component]
let make = (~onLogin, ~error=?) => {
  let (response, executeMutation) =
    ReasonUrql.Hooks.useDynamicMutation(LoginMutation.definition);
  let (email, setEmail) = React.useState(() => "");
  let (password, setPassword) = React.useState(() => "");

  React.useEffect1(
    () => {
      switch (response.response) {
      | Data(loginResp) when Belt.Option.isSome(loginResp##login) =>
        loginResp##login
        ->Belt.Option.map(resp => resp.user)
        ->Belt.Option.getExn
        ->onLogin
      | _ => ()
      };
      None;
    },
    [|response|],
  );

  <form onSubmit={e => ReactEvent.Form.preventDefault(e)}>
    <p> {React.string(Belt.Option.getWithDefault(error, ""))} </p>
    <input
      type_="text"
      value=email
      onChange={e => {
        let value = ReactEvent.Form.currentTarget(e)##value;
        setEmail(_ => value);
      }}
    />
    <input
      type_="password"
      value=password
      onChange={e => {
        let value = ReactEvent.Form.currentTarget(e)##value;
        setPassword(_ => value);
      }}
    />
    <button
      type_="submit"
      onClick={_ => executeMutation(~email, ~password, ()) |> ignore}>
      {React.string("Login")}
    </button>
  </form>;
};
