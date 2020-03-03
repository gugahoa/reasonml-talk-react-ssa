# Table of Contents

* Introdução
  * Quem sou eu
  * ReasonML e React
  * Por quê aprender ReasonML?
  * Quais dificuldades pessoas que estão começando costumam enfrentar?
* Hands On
  * Conceitos básicos de ReasonML
  * Começando um projeto
  * Fazendo routing
    * O que é pattern matching?
  * Como fazer um request http com fetch
    * `external` ou bs-fetch
    * GET e POST
  * Como desserializar um JSON para um tipo próprio?
    * Usando decco
  * Como usar GraphQL?
    * reason-apollo-hooks
    * reason-relay
    * reason-urql

# Introdução

## Quem sou eu

* Gustavo Aguiar, CTO e Co-founder do [Kinase](https://kinase.med.br)
  * Kinase é um preparatório pra residência médica
* Usamos ReasonML com ReasonReact no Kinase desde o ano passado, quando entrei
* Se quiser conversar sobre Rust, Elixir e ReasonML, teremos mto papo! :)

## ReasonML e React

* Criada pelo Jordan Walke, criador também de ReactJS e React Native
* Feita para ser acessível para quem vem de JavaScript
* ReasonML é uma linguagem de programação da familia ML
  * É uma sintáxe diferente em cima de OCaml
  * Pense em ReasonML como um primo de JavaScript, porém estaticamente tipado,
    mais rápido, sem o débito técnico histórico, e mais as features de OCaml,
    além de acesso a todo ecossistema OCaml e JavaScript já existente
* Jordan Walke: ReasonML é como trazer React para toda linguagem
* React trouxe conceitos de programação funcional para UI
  * Composable
  * Imutável

```javascript
let render = (friends) =>
  <div onClick={e => message(friends.length)}>
    {friends.map(friend => <div>{friend.name}</div>)}
  </div>
```

### Por quê aprender ReasonML?

* Sintáxe familiar para quem vem de JavaScript
* 100% de tipagem na sua codebase por padrão
* Inferência de tipos
* Garantia de soundness
  * Soundness é a garantia que uma vez compilado, é certeza que seus tipos
    estão corretos
* Simplicidade e pragmatismo - é possível optar por mutação e objetos, por 
  familiaridade ou interoperabilidade, ainda mantendo o resto do código puro e
  funcional
* Performance e tamanho - compilação incremental de 100ms ou menos, resultado
  pequeno e legível. (Adendo: As vezes vai otimizar tanto que o resultado vai
  ser um arquivo em branco)
* Ótimo ecossistema (com ressalvas) - bindings para as bibliotecas mais 
  famosas, compatibilidade com maior parte dos editores

### Quais dificuldades pessoas que estão começando costumam enfrentar?

* Terminologia
* Sintáxe bem parecida com JavaScript pode te convencer que você está 
  programando JavaScript, mas não é bem isso.
* Interoperabilidade pode ser bem difícil
* `/* This output is empty ... */`
* Muito conhecimento fragmentado, vários sites diferentes para documentação
* Carga cognitiva
* Mensagens de erros "erradas"

# Hands-on

## Basico

* Sintáxe
  * let
  * if - else
  * arrow function
  * switch
  * type
* Imutável por padrão, mas e se precisar mutar?
  * mutable
  * ref
* Tipos básicos
  * string
  * int
  * bool
  * float
* Estruturas de Dados
  * Listas e Arrays
  * Tuplas
  * Record
  * Variantes
* Modulos
  * Todo arquivo .re é um módulo
  * Não precisa importar modulos

## Começando um projeto

`bsb -init meu_app -theme react-hooks`
* Vamos explorar o que isso gera e rodar esse projeto
* O que é bucklescript?
* Como fazer routing?
* Como fazer um request http?
  * external ou bs-fetch
* Como desserializar o json resultante em um tipo?
* Como usar GraphQL?

# Fontes

- [Jordan Walke - React to the Future](https://www.youtube.com/watch?v=5fG_lyNuEAw)

