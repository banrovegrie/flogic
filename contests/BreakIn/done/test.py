hex = "475740444e6c4b5e5d15577a4315577a124d167a52144b58"
dec_list = []
for i in range(0, len(hex), 2):
    str = hex[i : i + 2]
    # print(str)
    dec_list.append(int(str, 16))
# print(dec_list)

for key in range(0, 256):
    d = []
    for i in dec_list:
        d.append(chr(i ^ key))
    print(''.join(d))
