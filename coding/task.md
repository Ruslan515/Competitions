# 1. Использование final с JOIN

Использование ключевого слова final при выполнении JOIN
заставляет ClickHouse выполнять полное сканирование таблиц для
удаления дубликатов перед выполнением соединения.
Это значительно увеличивает время выполнения запроса, особенно на больших объемах данных.

# 2. Неэффективная фильтрация

Применение условий фильтрации where updated=today() and date=today()-1
после выполнения JOIN увеличивает количество обрабатываемых данных.
Более эффективным подходом будет сначала фильтровать каждую таблицу отдельно,
чтобы уменьшить объем данных перед соединением.

# 3. Использование JOIN вместо IN

JOIN может быть более затратным по ресурсам,
особенно когда обе таблицы содержат большое количество строк.
Использование конструкции IN может быть более эффективным
для проверки наличия соответствующих значений product_id между таблицами.

### Оптимизированный запрос:

```sql
SELECT product_id
FROM products
WHERE updated = today()
  AND product_id IN (SELECT DISTINCT product_id
                     FROM remainders
                     WHERE
    date = today() - 1
    )
```