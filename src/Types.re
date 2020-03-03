type user = {
  name: string,
  email: string,
};

type auth_user =
  | Anonymous
  | LoggedIn(user)
