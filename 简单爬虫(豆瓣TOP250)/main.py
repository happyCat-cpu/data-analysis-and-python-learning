import requests
from bs4 import BeautifulSoup
import csv

# 伪装浏览器
headers = {
    "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/120.0.0.0 Safari/537.36"
}

# 存储所有电影
all_movies = []

# 循环爬取 10 页
for page in range(10):
    start = page * 25
    url = f"https://movie.douban.com/top250?start={start}"
    
    # 发送请求
    response = requests.get(url, headers=headers)
    response.encoding = 'utf-8'
    
    # 解析 HTML
    soup = BeautifulSoup(response.text, 'html.parser')
    items = soup.find_all('div', class_='item')
    
    # 提取当前页的电影数据
    for item in items:
        # 电影名称
        title_tag = item.find('span', class_='title')
        title = title_tag.text if title_tag else ''
        
        # 评分
        rating_tag = item.find('span', class_='rating_num')
        rating = rating_tag.text if rating_tag else ''
        
        # 评价人数
        star_tag = item.find('div', class_='star')
        star_text = star_tag.text.strip() if star_tag else ''
        if '人评价' in star_text:
            eval_num = star_text.split('人评价')[0].replace('(', '').replace(')', '')
        else:
            eval_num = ''
        
        # 一句话短评（可能没有）
        quote_tag = item.find('span', class_='inq')
        quote = quote_tag.text if quote_tag else ''
        
        all_movies.append({
            'title': title,
            'rating': rating,
            'eval_num': eval_num,
            'quote': quote
        })
    
    print(f"第 {page+1} 页爬取完成，当前共 {len(all_movies)} 条数据")

# 保存到 CSV
with open('douban_top250.csv', 'w', newline='', encoding='utf-8-sig') as f:
    writer = csv.DictWriter(f, fieldnames=['title', 'rating', 'eval_num', 'quote'])
    writer.writeheader()
    writer.writerows(all_movies)

print(f"爬取完成，共 {len(all_movies)} 条数据，已保存到 douban_top250.csv")