#简单购物系统2.0

products = [["iphone",6888,10],
            ["MacPro",14800,10],
            ["小米6",2499,10],
            ["coffee",30,50],
            ["Book",60,100],
            ["苹果",10,100],
            ["梨子",10,100],
            ["鸡蛋",10,100]]

cart = []

#==========
#=选择系统=
#==========
def show_products():
    print("\n=== 商品列表 ===")
    print("编号\t名称\t单价\t库存")
    for i, p in enumerate(products, 1):
        print(f"{i}\t{p[0]}\t¥{p[1]:.2f}\t{p[2]}")

def add_to_cart():
    try:
        idx = int(input("请输入商品编码：")) - 1 
        if not (0 <= idx < len(products)):
            print("没有该商品")
            return

        num = int(input("输入购入数量："))
        if num <= 0:
            print("数量必须大于0")
            return

        if num > products[idx][1]:
            print("库存不足，当前库存{products[idx][2]}")
            return

        #库存减少
        products[idx][2] -= num

        #检查购物车是否有该商品
        for item in cart:
            if item[0] == products[idx]:
                item[1] += num
                print(f"购物车已有{products[idx][0]},数量为{item[1]}")
                return

        #新商品
        cart.append([products[idx],num])
        print(f"已添加{products[idx][0]} x {num}到购物车")

    except ValueError:
        print("请输入有效数字")

def show_cart():
    if not cart:
        print("购物车是空的")
        return

    print("\n===购物车===")
    total = 0
    for i,(item,qty) in enumerate(cart,1):
        name = item[0]
        price = item[1]
        subtotal = price * qty
        total += subtotal
        print(f"{i}.{name} x {qty} = ${subtotal:.2f}(单价${price:.2f})")
    print(f"总价:${total:.2f}")

def remove_from_cart():
    if len(cart) == 0:
        print("购物车是空的")
        return
    print("\n===当前购物车===")
    for i,(item,qty) in enumerate(cart,1):
        name = item[0]
        price = item[1]
        subtotal = price * qty
        print(f"{i}.{name} x {qty} = ${subtotal:.2f}(单价${price:.2f})")
        
    try:
        choice = input("\n请选择操作: 1. 减少数量  2. 完全删除商品  3. 返回: ")
        
        if choice == '1':
            # 减少数量
            idx = int(input("请输入要减少的商品编号: ")) - 1
            if idx < 0 or idx >= len(cart):
                print("编号无效")
                return
            
            num = int(input("请输入要减少的数量: "))
            if num <= 0:
                print("数量必须大于0")
                return
            
            if num > cart[idx][1]:
                print(f"减少数量超过购物车数量，当前有 {cart[idx][1]} 件")
                return
            
            # 减少数量
            cart[idx][1] -= num
            # 把库存加回去
            cart[idx][0][2] += num
            
            if cart[idx][1] == 0:
                removed = cart.pop(idx)
                print(f"已从购物车移除 {removed[0][0]}")
            else:
                print(f"已减少 {num} 件，剩余 {cart[idx][1]} 件")
        
        elif choice == '2':
            # 完全删除商品
            idx = int(input("请输入要删除的商品编号: ")) - 1
            if idx < 0 or idx >= len(cart):
                print("编号无效")
                return
            
            # 把库存加回去
            cart[idx][0][2] += cart[idx][1]
            removed = cart.pop(idx)
            print(f"已从购物车删除 {removed[0][0]}")
        
        elif choice == '3':
            return
        
        else:
            print("无效选择")
            
    except ValueError:
        print("请输入有效数字")


def checkout():
    if not cart:
        print("购物车是空的")
        return

    total = 0
    print("\n===购物清单===")
    for item,qty in cart:
        name = item[0]
        price = item[1]
        subtotal = price * qty
        total += subtotal
        print(f"{name} x {qty} = ${subtotal:.2f}")
    print(f"\n总价:${total:.2f}")

    #支付方式
    print("\n支付方式：")
    print("1.支付宝")
    print("2.微信支付")

    pay = input("请选择支付方式:")
    print("支付成功！谢谢惠顾！")

    cart.clear()

#==========
#==主系统==
#==========
while True:
    print("\n","="*30)
    print("1.商品列表")
    print("2.购买商品")
    print("3.去除商品")
    print("4.查看购物车")
    print("5.结账")
    print("6.退出购物")

    choice = input("请输入你的选择:")

    #选择1
    if choice == '1':
        show_products()

    #选择2
    elif choice == '2':
        show_products()
        add_to_cart()
        
    #选择3
    elif choice == '3':
        remove_from_cart()

    #选择4
    elif choice == '4':
        show_cart()

    #选择5
    elif choice == '5':
        checkout()

    #选择6
    elif choice == '6':
        print("欢迎下次光临！")
        break

    else:
        print("无效选择")
