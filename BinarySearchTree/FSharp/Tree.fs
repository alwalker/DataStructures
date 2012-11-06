module Tree

type Node<'a> = { Item: 'a; mutable Left: Node<'a> option; mutable Right: Node<'a> option; Parent: Node<'a> option }


let rec add (parent: Node<'a> option) (node: Node<'a> option) (item: 'a) =
    match node with
    | None ->
        match parent with
        | Some parent when item < parent.Item -> 
            parent.Left <- Some {Item = item; Left = None; Right = None; Parent = Some parent }
        | Some parent when item > parent.Item ->
            parent.Right <- Some {Item = item; Left = None; Right = None; Parent = Some parent }
        | _ -> ()
    | Some node when item < node.Item -> add (Some node) node.Left item
    | Some node when item > node.Item -> add (Some node) node.Right item
    | _ -> ()

let rec find (node: Node<'a> option) (item: 'a) =
    match node with
    | Some node when item < node.Item -> find node.Left item
    | Some node when item > node.Item -> find node.Right item
    | Some node when item = node.Item -> Some node
    | _ -> None