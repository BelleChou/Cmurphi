const queenNUM:8;
      zero:0;
Type queen:1..queenNUM;
var
   a：array[queen] of Record  //记录所占的行数
    occupied:zero
    end;

   b,c,d:array[-7..16] of Record
	occupied:boolean
	end;

ruleset i : queen; j:queen do
		rule "occupied"         
    	(!b[i])&(!c[i+j])&(!d[j-i])
		==> begin
            a[j]:=i;//皇后j放置在i行
            b[i].occupied:=true;//占领第i行
            c[i+j].occupied:=true;//占领右上
            d[j-i].occupied:=true;//占领右下
    	endrule; 
endruleset;

startstate
begin
 for i: -7..16 do
    b[i].occupied:=false;//占领第i行
    c[i+j].occupied:=false;//占领右上
    d[j-i].occupied:=false;//占领右下 
  endfor;
endstartstate;
