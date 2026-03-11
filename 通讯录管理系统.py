#通讯录管理系统
contacts = [{"name":"小明","phone":"13800138000","address":"北京"},
            {"name":"小红","phone":"13800138001","address":"上海"}]

#===选择系统===
def show_contacts():
    print("="*10,"通讯录","="*10)
    for c in contacts:
        print(f"{c['name']}--{c['phone']}--{c['address']}")

def add_contacts():
    name = input("请输入名字：")
    phone = input("请输入电话：")
    address = input("请输入地址：")
    contacts.append({"name":name,"phone":phone,"address":address})
    print("添加成功")

def delete_contacts():
    name = input("请输入名字：")
    for i,c in enumerate(contacts):
        if c['name'] == name:
            del contacts[i]
            print(f"已删除联系人{name}")
            return
    print("没有此人")

def update_contacts():
    name = input("请输入名字：")
    for c in contacts:
        if c['name'] == name:
            print("1.修改电话")
            print("2.修改地址")
            print("3.修改全部")
            print("4.放弃修改")
            choice = input("选择修改选项：")
            if choice == '1':
                c['phone'] = input("请输入新号码:")
                print("修改成功")
                return
            elif choice == '2':
                c['address'] = input("请输入新地址:")
                print("修改成功")
                return
            elif choice == '3':
                c['phone'] = input("请输入新号码:")
                c['address'] = input("请输入新地址:")
                print("修改成功")
                return
            elif choice == '4':
                return
            else:
                print("无效选择")
    print("没有此人")

def search_contacts():
    name = input("请输入名字：")
    for c in contacts:
        if c['name'] == name:
            print(f"电话:{c['phone']}--{c['address']}")
            return
    print("没有此人")

#===主循环===
while True:
    print("="*10,"选项","="*10)
    print("\t1.添加联系人")
    print("\t2.删除联系人")
    print("\t3.修改联系人")
    print("\t4.搜索联系人")
    print("\t5.显示所有联系人")
    print("\t6.退出")
    print("-"*30)

    choice = input("请选择你要进行的操作：")
    
    if choice == '1':
        add_contacts()
    elif choice == '2':
        delete_contacts()
    elif choice == '3':
        update_contacts()
    elif choice == '4':
        search_contacts()
    elif choice == '5':
        show_contacts()
    elif choice == '6':
        comfire = input("确定退出吗?(y/n):")
        if comfire == 'y':
            print("再见！")
            break
    else:
        print("无效选择")
        continue
