from datetime import datetime

def input_date(prompt="请输入日期（格式：YYYY-MM-DD）："):
    date_str = input(prompt)
    if not date_str:
        return datetime.now().strftime("%Y-%m-%d")
    return date_str

def input_amount(prompt="请输入金额:"):
    while True:
        try:
            amount = float(input(prompt))
            if amount <= 0:
                print("金额必须大于0")
                continue
            return amount
        except ValueError:
            print("金额必须是数字")

def input_category(prompt="请输入类别（如：餐饮、工资、购物）："):
    return input(prompt).strip()

def input_type(prompt="请输入类型（收入/支出）："):
    while True:
        typ = input(prompt).strip()
        if typ in ["收入", "支出"]:
            return typ
        print("类型只能是「收入」或「支出」")

def input_note(prompt="请输入备注（直接回车跳过）："):
    return input(prompt).strip()

def print_menu():
    print("\n" + "=" * 30)
    print("1. 添加记录")
    print("2. 查看所有记录")
    print("3. 查看汇总统计")
    print("4. 查看月度报告")
    print("5. 删除记录")
    print("6. 保存数据")
    print("7. 退出")
    print("=" * 30)
