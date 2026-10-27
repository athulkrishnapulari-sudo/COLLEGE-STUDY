def fair_seq(a):
    pos=[]
    neg=[]
    for x in a:
        if x>0:
            pos.append(x)
        else:
            neg.append(x)
    seq=[]
    i=0
    for x in a:
        if x<0 and (i==0 or seq[-1]>0):
            seq.append(x)
        elif x>0 and seq and seq[-1]<0:
            seq.append(x)

    print(seq)

A = [-1, 18, 13, 18, 2, 16,7,-1, -213, 11]
fair_seq(A)