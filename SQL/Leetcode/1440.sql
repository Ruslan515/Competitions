-- https://leetcode.com/problems/evaluate-boolean-expression/
with t1 as (
    select
        e.*,
        v.value as value_left
    from expressions e join Variables v on e.left_operand = v.name
),
    t2 as (
        select
            t1.*,
            v.value as value_right
        from t1 join Variables v on t1.right_operand = v.name
    )

select
    left_operand,
    operator,
    right_operand,
    case
        when t2.operator = '=' then if(value_left = value_right, 'true', 'false')
        when t2.operator = '>' then if(value_left > value_right, 'true', 'false')
        when t2.operator = '<' then if(value_left < value_right, 'true', 'false')
    end as value
from t2
