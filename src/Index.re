open ReasonUrql;

let client = Client.make(~url="http://localhost:4000/graphql", ());

ReactDOMRe.renderToElementWithId(<Provider value=client> <App /> </Provider>, "app");
