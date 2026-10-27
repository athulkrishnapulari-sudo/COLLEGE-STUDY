def solve(heads,legs):
    for chick in range(0,heads+1):
        rab=heads-chick
        if (2*chick + 4*rab)==legs:
            return chick
    return None

heads=35
legs=94

chicks=solve(heads,legs)
rab = heads-chicks

print(chicks)
print(rab)
