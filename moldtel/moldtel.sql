/*
SQLyog Ultimate v9.20 
MySQL - 5.5.22 
*********************************************************************
*/
/*!40101 SET NAMES utf8 */;

create table `moldtel_data` (
	`id` int (11),
	`tarif_name` varchar (450),
	`minutes` int (11),
	`price` float ,
	`type` char (27)
); 
insert into `moldtel_data` (`id`, `tarif_name`, `minutes`, `price`, `type`) values('1','local_min_10','50','10','packet');
insert into `moldtel_data` (`id`, `tarif_name`, `minutes`, `price`, `type`) values('2','local_min_18','100','18','packet');
insert into `moldtel_data` (`id`, `tarif_name`, `minutes`, `price`, `type`) values('3','local_min_30','200','30','packet');
insert into `moldtel_data` (`id`, `tarif_name`, `minutes`, `price`, `type`) values('4','national_min_10','30','10','packet');
insert into `moldtel_data` (`id`, `tarif_name`, `minutes`, `price`, `type`) values('5','national_min_18','60','18','packet');
insert into `moldtel_data` (`id`, `tarif_name`, `minutes`, `price`, `type`) values('6','national_min_25','90','25','packet');
insert into `moldtel_data` (`id`, `tarif_name`, `minutes`, `price`, `type`) values('7','mob_min_30','20','30','packet');
insert into `moldtel_data` (`id`, `tarif_name`, `minutes`, `price`, `type`) values('8','mob_min_55','40','55','packet');
insert into `moldtel_data` (`id`, `tarif_name`, `minutes`, `price`, `type`) values('9','mob_min_75','60','75','packet');
insert into `moldtel_data` (`id`, `tarif_name`, `minutes`, `price`, `type`) values('10','rus_min_65','20','65','packet');
insert into `moldtel_data` (`id`, `tarif_name`, `minutes`, `price`, `type`) values('11','rus_min_120','40','120','packet');
insert into `moldtel_data` (`id`, `tarif_name`, `minutes`, `price`, `type`) values('12','rus_min_160','60','160','packet');
insert into `moldtel_data` (`id`, `tarif_name`, `minutes`, `price`, `type`) values('13','eu_usa_min_70','15','70','packet');
insert into `moldtel_data` (`id`, `tarif_name`, `minutes`, `price`, `type`) values('14','eu_usa_min_125','30','125','packet');
insert into `moldtel_data` (`id`, `tarif_name`, `minutes`, `price`, `type`) values('15','eu_usa_min_165','45','165','packet');
insert into `moldtel_data` (`id`, `tarif_name`, `minutes`, `price`, `type`) values('16','mix 50 national_min','140','50','packet');
insert into `moldtel_data` (`id`, `tarif_name`, `minutes`, `price`, `type`) values('17','mix 50 mob_min','35','50','packet');
insert into `moldtel_data` (`id`, `tarif_name`, `minutes`, `price`, `type`) values('18','mix 50 rus_min','15','50','packet');
insert into `moldtel_data` (`id`, `tarif_name`, `minutes`, `price`, `type`) values('19','mix 50 eu_usa_min','10','50','packet');
insert into `moldtel_data` (`id`, `tarif_name`, `minutes`, `price`, `type`) values('20','mix 100 national_min','320','100','packet');
insert into `moldtel_data` (`id`, `tarif_name`, `minutes`, `price`, `type`) values('21','mix 100 mob_min','75','100','packet');
insert into `moldtel_data` (`id`, `tarif_name`, `minutes`, `price`, `type`) values('22','mix 100 rus_min','30','100','packet');
insert into `moldtel_data` (`id`, `tarif_name`, `minutes`, `price`, `type`) values('23','mix 100 eu_usa_min','20','100','packet');
insert into `moldtel_data` (`id`, `tarif_name`, `minutes`, `price`, `type`) values('24','mix 150 national_min','550','150','packet');
insert into `moldtel_data` (`id`, `tarif_name`, `minutes`, `price`, `type`) values('25','mix 150 mob_min','120','150','packet');
insert into `moldtel_data` (`id`, `tarif_name`, `minutes`, `price`, `type`) values('26','mix 150 rus_min','50','150','packet');
insert into `moldtel_data` (`id`, `tarif_name`, `minutes`, `price`, `type`) values('27','mix 150 eu_usa_min','35','150','packet');
insert into `moldtel_data` (`id`, `tarif_name`, `minutes`, `price`, `type`) values('28','st','300','24','abonament');
insert into `moldtel_data` (`id`, `tarif_name`, `minutes`, `price`, `type`) values('29','ec','200','6','abonament');
insert into `moldtel_data` (`id`, `tarif_name`, `minutes`, `price`, `type`) values('30','in','700','6','abonament');
insert into `moldtel_data` (`id`, `tarif_name`, `minutes`, `price`, `type`) values('31','st add','1','0.084','abonament');
insert into `moldtel_data` (`id`, `tarif_name`, `minutes`, `price`, `type`) values('32','ec add','1','0.144','abonament');
insert into `moldtel_data` (`id`, `tarif_name`, `minutes`, `price`, `type`) values('33','in add','1','0.12','abonament');
