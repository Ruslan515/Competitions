drop table if exists rtz_t_whs_site_constitusion;
create table rtz_t_whs_site_constitusion ENGINE = MergeTree
                                                  (
                                                  ) ORDER BY whs_id as;

select h.whs_id   whs_id,
       h.jsite_id site_id,
       id_sitetype
from (select hier_level_1.whs_id whs_id, jsite_id
      from (select *
            from (select *
                  from iimp.rtz_v_site_hier_lnk h
                           join (select whs_id, p.site_id
                                 from iimp.rtz_v_site_attr a
                                          join (select whs_id, site_id
                                                from iimp.rtz_t_site_whs_per
                                                where begin_dt < toString(toDate(now(), 'Europe/Moscow'))
                                                  and end_dt > toString(toDate(now(), 'Europe/Moscow'))) p
                                               on a.site_id = p.site_id
                                 where attr_type_id = '1') p on p.site_id = h.site_id) hier_level_1
                     left join (select * from iimp.rtz_v_site_hier_lnk where site_parent_id <> '') hier_level_2
                               on hier_level_2.site_parent_id = hier_level_1.site_id
                     left join (select * from iimp.rtz_v_site_hier_lnk where site_parent_id <> '') hier_level_3
                               on hier_level_3.site_parent_id = hier_level_2.site_id
                     left join (select * from iimp.rtz_v_site_hier_lnk where site_parent_id <> '') hier_level_4
                               on hier_level_4.site_parent_id = hier_level_3.site_id
                     left join (select * from iimp.rtz_v_site_hier_lnk where site_parent_id <> '') hier_level_5
                               on hier_level_5.site_parent_id = hier_level_4.site_id)
               ARRAY JOIN
           [hier_level_1.site_id
               , hier_level_2.site_id
               , hier_level_3.site_id
               , hier_level_4.site_id
               , hier_level_5.site_id] AS jsite_id
      where whs_id <> ''
        and jsite_id <> ''
      group by hier_level_1.whs_id, jsite_id
      order by hier_level_1.whs_id asc) h
         join iimp.rtz_v_site s on s.site_id = h.jsite_id
         join iimp.rtz_v_sitetype st on st.sitetype_id = s.id_sitetype;
доступно
контекстное меню