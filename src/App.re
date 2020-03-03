[@react.component]
let make = () => {
  let url = ReasonReactRouter.useUrl();

  switch (url.path) {
  | [name] => <Greeter name />
  | _ => <div> {React.string("Hello, world")} </div>
  };
};
