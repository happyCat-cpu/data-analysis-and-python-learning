from models import AccountManager
from utils import input_date, input_amount, input_category, input_type, input_note, print_menu

def main():
    manager = AccountManager()

    while True:
        print_menu()
        choice = input("请选择(1-7)：")
        
        if choice == '1':
            print("\n--- 添加记录 ---")
            date = input_date("请输入日期（格式：2025-04-08，直接回车使用今天）")
            category = input_category()
            amount = input_amount()
            typ = input_type()
            note = input_note()
            print(manager.add(date, category, amount, typ, note))
        
        elif choice == '2':
            print(manager.show_all())
        
        elif choice == '3':
            print(manager.get_summary())
        
        elif choice == '4':
            year_month = input("请输入年月（格式：2025-04）：")
            print(manager.get_monthly_report(year_month))
        
        elif choice == '5':
            try:
                record_id = int(input("请输入要删除的ID："))
                print(manager.delete(record_id))
            except ValueError:
                print("ID必须是数字")
        
        elif choice == '6':
            manager.save()
            print("数据已保存")
        
        elif choice == '7':
            manager.save()
            print("再见！")
            break
        
        else:
            print("无效选择，请重新输入")

if __name__ == "__main__":
    main()
