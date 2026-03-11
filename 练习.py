"""
#统计单词出现次数
sentence = "apple banana apple orange banana apple"
words = sentence.split()

word_count ={}

for word in words:
    if word in word_count:
        word_count[word] += 1
    else:
        word_count[word] = 1

print(word_count)
"""
"""
#两门课的成绩
python_scores = {"小明":85,"小红":92,"小刚":78,"小丽":88}
Java_scores = {"小明":90,"小红":88,"小刚":82,"小强":95}

set1 =  set(python_scores.keys())
set2 = set(Java_scores.keys())
both = set1 & set2
print(both)

avg_scores = {}
for name in both:
    avg = (python_scores[name] + Java_scores[name]) / 2
    avg_scores[name] = avg
print(avg_scores)

good = [s for s,a in avg_scores.items() if a > 85]
print(good)
"""

#购物模拟
products = {"苹果":50,
            "香蕉":30,
            "牛奶":20,
            "面包":15}

cart = {}

#打印商品栏
print("="*15)
for i,(name,stock) in enumerate(products.items(),1):
    print(f"{i}.{name}-{stock}")

#购买商品
while True:
    name = input("想购入商品的名称是(按q退出)：")
    if name == 'q':
        break
    if name not in products:
        print("没有该商品")
        continue

    try:
        num = int(input("输入购买数量:"))
        if num <= 0:
            print("数量要大于0")
            continue
        if num > products[name]:
            print("没有多余库存")
            continue

        products[name] -= num
        print(f"购买成功,剩余{products[name]}件")

    except ValueError:
        print("无效数字")
    
