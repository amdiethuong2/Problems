const fi='';//'seating.inp';
      fo='';//'seating.out';
      maxn=1000000005;
      maxm=1000000005;

Type phantu=record
     cs,va:longint;
     end;

var n,m,k:longint;
    a,b:array[1..50] of longint;
    c:array[1..50 ] of phantu;
    f1,f2:text;
    kq:int64;

Procedure nhap;
var i,j:longint;
Begin
    Assign(f1,fi);
    reset(f1);
    readln(f1,n,m,k);
    For i:=1 to k do
    Begin
        readln(f1,a[i],b[i]);
        c[i].cs:=a[i];
        c[i].va:=b[i];
    end;
    close(f1);
end;

Function ss(p,q:phantu):longint;
begin
    If p.cs<q.cs then exit(-1);
    If p.cs=q.cs then
    If p.va<q.va then exit(-1);
    exit(1);
end;

Procedure sort(l,r:longint);
Var i,j:longint;
    t,k:phantu;
Begin
    If l>r then exit;
    i:=l;
    j:=r;
    k:=c[random(j-i+1)+i];
    repeat
         Begin
             While ss(c[i],k)=-1 do inc(i);
             While ss(k,c[j])=-1 do dec(j);
             If i<=j then
             Begin
                 t:=c[i];
                 c[i]:=c[j];
                 c[j]:=t;
                 inc(i);
                 dec(j);
             end;
         end;
    until(i>j);
    sort(l,j);
    sort(i,r);
end;


Procedure xuly;
Var i,j:longint;
    tg:phantu;
Begin
    sort(1,k);
    kq:=(m-1)*n-(m-1);
    tg:=c[1];
    if c[1].va>1 then
     kq:=kq+tg.va-2 else kq:=kq;
     If k=1 then
     if tg.va<m then
     kq:=kq+(m-tg.va-1);
    for i:=2 to k do
    Begin
        if c[i].cs<>tg.cs then
        begin
            If tg.va<m then
            kq:=kq+(m-tg.va-1);
            kq:=kq-(m-1);
            If c[i].va=1 then kq:=kq else
            kq:=kq+c[i].va-2;
            tg:=c[i];
            If i=k then
            Begin
                 If c[i].va<m then
                kq:=kq+(m-tg.va-1);
            end;
        end else
        Begin
            kq:=kq+c[i].va-tg.va-2;
            tg.va:=c[i].va   ;
            If i=k then
            Begin
                If c[i].va<m then
                kq:=kq+(m-tg.va-1);
            end;
        end;
    end;
end;

Procedure inkq;
Begin
    Assign(f2,fo);
    rewrite(f2);
    Writeln(f2,kq);
    close(f2);
end;

Begin
    nhap;
    xuly;
    inkq;
end.
