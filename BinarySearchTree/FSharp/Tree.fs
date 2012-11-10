module Tree
open System

[<CustomEquality; NoComparisonAttribute>]
type Node<'a> = 
    { mutable Item: 'a; mutable Left: Node<'a> option; mutable Right: Node<'a> option; mutable Parent: Node<'a> option }
    override x.Equals(other) =
        obj.ReferenceEquals(x, other)
    override x.GetHashCode() =
        hash x
    interface IEquatable<Node<'a>> with
        member this.Equals(other) =
            obj.ReferenceEquals(this, other)

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

let rec delete (node: Node<'a> option) (item: 'a) =
    match node with
    | None -> ()
    | Some node when item < node.Item -> delete node.Left item
    | Some node when item > node.Item -> delete node.Right item
    | Some node when item = node.Item && node.Left.IsSome && node.Right.IsSome ->
        node.Item <- node.Left.Value.Item
        delete node.Left node.Left.Value.Item
    | Some node when item = node.Item && node.Left.IsNone && node.Right.IsNone ->
        match node.Parent with
        | None -> printf "You tried to delete root" //figure out how to do this
        | x when x.Value.Left = Some node -> node.Parent.Value.Left <- None
        | x when x.Value.Right = Some node -> node.Parent.Value.Right <- None
        | _ -> ()
    | Some node when item = node.Item && node.Left.IsNone && node.Right.IsSome ->
        match node.Parent with
        | None -> printf "You tried to delete the right node of root" //figure out how to do this
        | parent when parent.Value.Left = Some node -> 
            node.Parent.Value.Left <- node.Right
            node.Left.Value.Parent <- parent
        | parent when parent.Value.Right = Some node -> 
            node.Parent.Value.Right <- node.Right
            node.Right.Value.Parent <- parent
        | _ -> ()
    | Some node when item = node.Item && node.Left.IsSome && node.Right.IsNone ->
        match node.Parent with
        | None -> printf "You tried to delete the left node of root" //figure out how to do this
        | parent when parent.Value.Left = Some node -> 
            node.Parent.Value.Left <- node.Left
            node.Left.Value.Parent <- parent
        | parent when parent.Value.Right = Some node ->
            node.Parent.Value.Right <- node.Left
            node.Right.Value.Parent <- parent
        | _ -> ()
    | _ -> ()

let rec find (node: Node<'a> option) (item: 'a) =
    match node with
    | Some node when item < node.Item -> find node.Left item
    | Some node when item > node.Item -> find node.Right item
    | Some node when item = node.Item -> Some node
    | _ -> None

let rec traverse(node: Node<'a> option) f =
    match node with
    | None -> ()
    | Some node ->
        traverse node.Left f
        f node.Item
        traverse node.Right f