﻿// Learn more about F# at http://fsharp.net
// See the 'F# Tutorial' project for more help.

module Program

open System

[<EntryPoint>]
let main argv = 
    printfn "%A" argv
    Console.ReadLine() |> ignore
    0 // return an integer exit code
