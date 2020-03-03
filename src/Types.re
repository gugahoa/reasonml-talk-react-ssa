[@decco]
type user = {
  name: string,
  email: string,
};

[@decco]
type login_resp = {
  token: string,
  user: user,
};

type auth_user =
  | Anonymous
  | LoggedIn(user)
