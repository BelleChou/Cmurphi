const clientNUMS : 2;
type state : enum{I, T, C, E};

     client: 1..clientNUMS;

var n : array [client] of state;

    x : boolean; 
    
ruleset i : client do
rule "Try" n[i] = I ==> begin
      n[i] := T;endrule; 

rule "Crit"
      n[i] = T& x = true ==>begin
      n[i] := C; x := false; endrule;

rule "Exit"
      n[i] = C ==>begin
      n[i] := E;endrule;
      
 
rule "Idle"
      n[i] = E ==> begin n[i] := I;
      x := true;endrule;
endruleset;

startstate
begin
 for i: client do
    n[i] := I; 
  endfor;
  x := true;
endstartstate;

ruleset i:client; j: client do
invariant "coherence"
  i != j -> (n[i] = C -> n[j] != C);
endruleset;

ruleset i:client; j: client do 
invariant "c51"
i != j    -> 
  (n[j] = C -> n[i] != E);
endruleset;

ruleset i:client; j: client do 
invariant "52"
i != j & i != Home & j != Home  -> 
  (n[i] != T & n[i] != I -> n[j] != E)
endruleset;
