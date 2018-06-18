const queenNUM:8;
      zero:0;
Type queen:1..queenNUM;
var
<<<<<<< HEAD
   a：array[queen] of Record  //记录所占的行数
=======
   a：array[queen] of Record
>>>>>>> 7de067a1a1999fc39b1b9a23061b207eaa833d6a
    occupied:zero
    end;

   b,c,d:array[-7..16] of Record
	occupied:boolean
	end;

ruleset i : queen; j:queen do
		rule "occupied"         
    	(!b[i])&(!c[i+j])&(!d[j-i])
		==> begin
<<<<<<< HEAD
            a[j]:=i;//皇后j放置在i行
=======
            a[j]:=i;//皇后放置在此行
>>>>>>> 7de067a1a1999fc39b1b9a23061b207eaa833d6a
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
