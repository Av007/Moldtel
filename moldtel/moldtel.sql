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
	`type` char (27),
	`name` varchar (1650)
); 
insert into `moldtel_data` (`id`, `tarif_name`, `minutes`, `price`, `type`, `name`) values('1','local_min_10','50','10','packet','Minute locale 10');
insert into `moldtel_data` (`id`, `tarif_name`, `minutes`, `price`, `type`, `name`) values('2','local_min_18','100','18','packet','Minute locale 18');
insert into `moldtel_data` (`id`, `tarif_name`, `minutes`, `price`, `type`, `name`) values('3','local_min_30','200','30','packet','Minute locale 30');
insert into `moldtel_data` (`id`, `tarif_name`, `minutes`, `price`, `type`, `name`) values('4','national_min_10','30','10','packet','Minute naţionale 10');
insert into `moldtel_data` (`id`, `tarif_name`, `minutes`, `price`, `type`, `name`) values('5','national_min_18','60','18','packet','Minute naţionale 18');
insert into `moldtel_data` (`id`, `tarif_name`, `minutes`, `price`, `type`, `name`) values('6','national_min_25','90','25','packet','Minute naţionale 25');
insert into `moldtel_data` (`id`, `tarif_name`, `minutes`, `price`, `type`, `name`) values('7','mob_min_30','20','30','packet','Minute mobile 30');
insert into `moldtel_data` (`id`, `tarif_name`, `minutes`, `price`, `type`, `name`) values('8','mob_min_55','40','55','packet','Minute mobile 55');
insert into `moldtel_data` (`id`, `tarif_name`, `minutes`, `price`, `type`, `name`) values('9','mob_min_75','60','75','packet','Minute mobile 75');
insert into `moldtel_data` (`id`, `tarif_name`, `minutes`, `price`, `type`, `name`) values('10','rus_min_65','20','65','packet','Minute cu Rusia 65');
insert into `moldtel_data` (`id`, `tarif_name`, `minutes`, `price`, `type`, `name`) values('11','rus_min_120','40','120','packet','Minute cu Rusia 120');
insert into `moldtel_data` (`id`, `tarif_name`, `minutes`, `price`, `type`, `name`) values('12','rus_min_160','60','160','packet','Minute cu Rusia 160');
insert into `moldtel_data` (`id`, `tarif_name`, `minutes`, `price`, `type`, `name`) values('13','eu_usa_min_70','15','70','packet','Minute cu Europa şi SUA 70');
insert into `moldtel_data` (`id`, `tarif_name`, `minutes`, `price`, `type`, `name`) values('14','eu_usa_min_125','30','125','packet','Minute cu Europa şi SUA 125');
insert into `moldtel_data` (`id`, `tarif_name`, `minutes`, `price`, `type`, `name`) values('15','eu_usa_min_165','45','165','packet','Minute cu Europa şi SUA 165');
insert into `moldtel_data` (`id`, `tarif_name`, `minutes`, `price`, `type`, `name`) values('16','mix 50 national_min','140','50','packet','Mix 50');
insert into `moldtel_data` (`id`, `tarif_name`, `minutes`, `price`, `type`, `name`) values('17','mix 50 mob_min','35','50','packet','Mix 50');
insert into `moldtel_data` (`id`, `tarif_name`, `minutes`, `price`, `type`, `name`) values('18','mix 50 rus_min','15','50','packet','Mix 50');
insert into `moldtel_data` (`id`, `tarif_name`, `minutes`, `price`, `type`, `name`) values('19','mix 50 eu_usa_min','10','50','packet','Mix 50');
insert into `moldtel_data` (`id`, `tarif_name`, `minutes`, `price`, `type`, `name`) values('20','mix 100 national_min','320','100','packet','Mix 100');
insert into `moldtel_data` (`id`, `tarif_name`, `minutes`, `price`, `type`, `name`) values('21','mix 100 mob_min','75','100','packet','Mix 100');
insert into `moldtel_data` (`id`, `tarif_name`, `minutes`, `price`, `type`, `name`) values('22','mix 100 rus_min','30','100','packet','Mix 100');
insert into `moldtel_data` (`id`, `tarif_name`, `minutes`, `price`, `type`, `name`) values('23','mix 100 eu_usa_min','20','100','packet','Mix 100');
insert into `moldtel_data` (`id`, `tarif_name`, `minutes`, `price`, `type`, `name`) values('24','mix 150 national_min','550','150','packet','Mix 150');
insert into `moldtel_data` (`id`, `tarif_name`, `minutes`, `price`, `type`, `name`) values('25','mix 150 mob_min','120','150','packet','Mix 150');
insert into `moldtel_data` (`id`, `tarif_name`, `minutes`, `price`, `type`, `name`) values('26','mix 150 rus_min','50','150','packet','Mix 150');
insert into `moldtel_data` (`id`, `tarif_name`, `minutes`, `price`, `type`, `name`) values('27','mix 150 eu_usa_min','35','150','packet','Mix 150');
insert into `moldtel_data` (`id`, `tarif_name`, `minutes`, `price`, `type`, `name`) values('28','st','300','24','abonament','Standard');
insert into `moldtel_data` (`id`, `tarif_name`, `minutes`, `price`, `type`, `name`) values('29','ec','200','6','abonament','Econom');
insert into `moldtel_data` (`id`, `tarif_name`, `minutes`, `price`, `type`, `name`) values('31','st add','1','0.084','abonament',NULL);
insert into `moldtel_data` (`id`, `tarif_name`, `minutes`, `price`, `type`, `name`) values('32','ec add','1','0.24','abonament',NULL);
