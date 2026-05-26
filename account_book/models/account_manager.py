import os
import json
from datetime import datetime

class AccountManager:
    def __init__(self,filename = "data/accounts.json"):
        self.filename = filename
        self.records = []
        self.next_id = 1
        self.load()

    def add(self,date,category,amount,typ,note=""):
        if date is None:
            date = datetime.now().strftime("%Y-%m-%d")
        record = {
            "id":self.next_id,
            "date":date,
            "category":category,
            "amount":amount,
            "type":typ,
            "note":note
            }

        self.records.append(record)
        self.next_id += 1
        self.save()
        return f"添加成功,ID:{record['id']}"

    def show_all(self):
        if not self.records:
            return "还没有记录！"
        output = "===所有记录===\n"
        for each in self.records:
            output += f"序号: {each['id']}\n"
            output += f"日期: {each['date']}\n"
            output += f"类别: {each['category']}\n"
            output += f"金额: {each['amount']}\n"
            output += f"类型: {each['type']}\n"
            output += f"备注: {each['note']}\n"
            output += "-" * 20 + "\n"
        return output

    def get_summary(self):
        if not self.records:
            return "还没有记录！"
        income = sum(r["amount"] for r in self.records if r["type"] == "收入")
        expense = sum(r["amount"] for r in self.records if r["type"] == "支出")
        balance = income - expense
        return f"总收入:{income}\n总支出:{expense}\n结余:{balance}\n"

    def get_monthly_report(self,year_month):
        if not self.records:
            return "还没有记录！"
        income = 0
        expense = 0
        for r in self.records:
            if r['date'].startswith(year_month):
                if r['type'] == '收入':
                    income += r['amount']
                else:
                    expense += r['amount']
        return f"=== {year_month} 报告 ===\n总收入: {income:.2f}\n总支出: {expense:.2f}\n结余: {income - expense:.2f}"

    def delete(self,record_id):
        if not self.records:
            return "还没有记录！"
        for i,r in enumerate(self.records):
            if r['id'] == record_id:
                del self.records[i]
                self.save()
                return f"已删除 ID {record_id}"
        return f"ID {record_id} 不存在"

    def save(self):
        os.makedirs(os.path.dirname(self.filename),exist_ok=True)
        with open(self.filename,'w',encoding = 'utf-8') as f:
            json.dump({
                "next_id":self.next_id,
                "records":self.records
                },f,ensure_ascii=False,indent=2)

    def load(self):
        if os.path.exists(self.filename):
            try:
                with open(self.filename,'r',encoding = 'utf-8') as f:
                    data = json.load(f)
                    self.next_id = data.get("next_id",1)
                    self.records = data.get("records",[])
            except:
                self.records = []
                self.next_id = 1
        
