type
	val_t: 0..16;
	arr_t: Array [val_t] of val_t;
	type cmp_type : 
	record
		length : val_t;
		arr: arr_t;
	end;

var
	x : val_t;
	y : val_t;
	r : val_t;
	temp: val_t;
	arr_i: arr_t;
	
	arr_1:cmp_type;
	arr_xy:cmp_type;

Procedure gcd(Var x,y,r: val_t);
begin
	while r!= 0 do
		x := y;
		y := r;
		r := x % y;
	end;
	put(y);
end;

procedure commonDivdors(x,y: val_t; Var cmp:cmp_type);
Var 
	a: val_t;
	b: val_t;
	temp : val_t;
	i,j : val_t;
	arr : arr_t;
begin
	a := x;
	b := y;
	temp := y;
	i := 0;
	if a < b then
		temp :=a;
	else temp:=b;
	endif;
	
	while temp > 0 do
		if (a % temp = 0) & (b % temp = 0) then
			cmp.arr[i] := temp;
			i := i + 1;
			
		end;
		temp:=temp -1;
	end; 
	cmp.length:=i;
end;

Function compare(ar_1, ar_2: cmp_type): Boolean;
Var 
	i:val_t;
begin
	
	if (ar_1.length =ar_2.length) then 
	
	for i:= 0 to ar_1.length - 1  Do
		if ar_1.arr[i] != ar_2.arr[i] then
			return false;
		endif;
	endfor;
	return true;

	else return false;
	endif;
end;
	
		

rule r > 0 ==> begin gcd(x,y,r); end;
rule x < y ==> begin temp :=y; y := x; x := temp;  commonDivdors(x,y,arr_xy); end;
	
startstate
	x := 12;
	y := 16;
	r := x%y;
	commonDivdors(12,16,arr_1);
	commonDivdors(12,16,arr_xy);
end;

invariant "commonDivdors"
	compare(arr_1, arr_xy);
