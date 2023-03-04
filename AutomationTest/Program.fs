
let p = new System.Diagnostics.Process()
p.StartInfo.FileName    <- "C:\\Users\\Evelyn Borth\\source\\repos\\Bachelor\\x64\\Release\\Bachelor.exe"
p.StartInfo.Arguments                <- "--onlytime"
p.StartInfo.UseShellExecute          <- false
p.StartInfo.RedirectStandardInput    <- true
p.StartInfo.RedirectStandardOutput   <- true
p.StartInfo.RedirectStandardError    <- true

seq { 0 .. 9 }
|> List.ofSeq
|> List.map (fun _ ->
    let started = p.Start()
    let s = p.StandardOutput.ReadToEnd()
    p.WaitForExit()
    p.Close()
    double s)
|> List.average
|> printfn "Average of %f nanoseconds"