var
  x ,y: enum {a,b}; 
  
  --- y : enum {a,b};


 startstate "Init"
  x:=a; y:=b;
endstartstate;  


  rule "Store"
  x=a
==> begin
  y:=undefined;
endrule; 
