[@react.component]
let make = (~login, ~error=?) => {
  let (email, setEmail) = React.useState(() => "");
  let (password, setPassword) = React.useState(() => "");
  <form onSubmit={e => ReactEvent.Form.preventDefault(e)}>
    <p>{React.string(Belt.Option.getWithDefault(error, ""))}</p>
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
    <button type_="submit" onClick={_ => login(email, password)}> {React.string("Login")} </button>
  </form>;
};
