def sumatoria(b,i,d,s):
    
    res = 0
    ran = len(s)-1
    
    for x in range(d,i):
        print(x,": ",b,"^",x," *", int(s[ran]),"   =   ",(b**x)* int(s[ran]))
        res += (b**x)* int(s[ran])
        ran-=1
    return print("Resultado: ",res)
    
print("B =")
B = int(input())
print("W =")
w = input()
W = w.split(".")
if len(W) == 2:
    #punto
    sumatoria(B,len(W[0]),-(len(W[1])),W[0]+ W[1])
else:
    #no punto
    sumatoria( B,len(w), 0, w )