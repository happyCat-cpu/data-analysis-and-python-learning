products = [["iphone",6888],
            ["MacPro",14800],
            ["小米6",2499],
            ["Coffee",31],
            ["Book",60],
            ["Nike",699]]

print("======商品列表======")

cart = []
count = [0]*len(products)

for i in range(len(products)):
    name = products[i][0]
    price = products[i][1]
    print(f"{i+1}.{name}-{price}")

while True:
    choice = input("输入商品编码（按q结账）：")

    if choice == "q":
        break

    if choice.isdigit():
        idx = int(choice)-1

        if 0 <= idx < len(products):
            if count[idx] == 0:
                cart.append(products[idx])
            count[idx] += 1
            if count[idx] == 1:
                print(f"已添加{products[idx][0]}进购物车，现有{count[idx]}件")
            else:
                print(f"商品{products[idx][0]}数量+1，现有{count[idx]}件")
        else:
            print("编码无效，请重新输入")
    else:
        print("请输入数字 或者 q 退出")

print()
print("======购物车======")
total = 0
if len(cart) == 0:
    print("购物车是空的")
else:
    for item in cart:
        name = item[0]
        price = item[1]
        idx = products.index(item)
        quantity = count[idx]
        total += price*quantity
        print(f"{name}*{quantity}-${price}")
    print(f"总价:${total}")

input()
