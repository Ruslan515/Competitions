-- https://leetcode.com/problems/tree-node/
with temp as
    (
        select
            t1.id,
            t1.p_id as parent,
            t2.id as child
        from Tree t1 left join Tree t2 on (t1.id = t2.p_id)
    ),
-- select
--     *
-- from temp
temp1 as
    (
        select
            distinct id,
            'Root' as type
        from temp
        where parent is null
        union all
        select
            distinct id,
            'Inner' as type
        from temp
        where parent is not null and child is not null
        union all
        select
            distinct id,
            'Leaf' as type
        from temp
        where parent is not null and child is null
    )
select
    *
from temp1
order by id;
