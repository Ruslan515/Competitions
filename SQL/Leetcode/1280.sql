-- https://leetcode.com/problems/students-and-examinations/
with t1 as (
    select
        student_id,
        subject_name,
        count(*) as attended_exams
    from Examinations
    group by student_id, subject_name
),
    t2 as (
        select
            *
        from Students, Subjects
        order by student_id, subject_name
    )
select
    t2.student_id,
    t2.student_name,
    t2.subject_name,
    coalesce(t1.attended_exams, 0) as attended_exams
from t2 left join t1 on t2.student_id = t1.student_id and t2.subject_name = t1.subject_name
order by t2.student_id, t2.subject_name;
