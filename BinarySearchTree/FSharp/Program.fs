// Learn more about F# at http://fsharp.net
// See the 'F# Tutorial' project for more help.

module Program

open System
open Tree

[<EntryPoint>]
let main argv = 
    //printfn "%A" argv
    let root = {Item = 10; Left = None; Right = None; Parent = None}
    add None (Some root) 5
    add None (Some root) 4
    add None (Some root) 6
    add None (Some root) 15
    add None (Some root) 14
    add None (Some root) 16

    delete (Some root) 16

    printfn "%A" root
    Console.ReadLine() |> ignore
    0 // return an integer exit code
