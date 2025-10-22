text = "JIsWhJMCzbV:<5*'#|weh,!=puqmy#9:*mc"
key1 = "breakIn{"
key2 = "notFakeCTF{"

key = key1
for i in range(len(key)):
    val = ord(key[i]) ^ ord(text[i])
    print(val, end=',')

l = [40,59,22,54,3,3,35,56]
n = len(l)
for i in range(len(text)):
    val = ord(text[i]) ^ l[i % n]
    print(chr(val), end="")