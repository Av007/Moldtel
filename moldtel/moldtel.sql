DROP TABLE IF EXISTS `moldtel_data`;
CREATE TABLE `moldtel_data` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `tarif_name` varchar(128) NOT NULL,
  `minutes` int(11) NOT NULL,
  `price` float NOT NULL,
  `type` enum('packet','adding','plan') NOT NULL DEFAULT 'plan',
  `name` varchar(128) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

insert  into `moldtel_data`(`id`,`tarif_name`,`minutes`,`price`,`type`,`name`) values (1,'local_min_10',50,10,'packet','Minute locale 10'),(2,'local_min_18',100,18,'packet','Minute locale 18'),(3,'local_min_30',200,30,'packet','Minute locale 30'),(4,'national_min_10',30,10,'packet','Minute naţionale 10'),(5,'national_min_18',60,18,'packet','Minute naţionale 18'),(6,'national_min_25',90,25,'packet','Minute naţionale 25'),(7,'mob_min_30',20,30,'packet','Minute mobile 30'),(8,'mob_min_55',40,55,'packet','Minute mobile 55'),(9,'mob_min_75',60,75,'packet','Minute mobile 75'),(10,'rus_min_65',20,65,'packet','Minute cu Rusia 65'),(11,'rus_min_120',40,120,'packet','Minute cu Rusia 120'),(12,'rus_min_160',60,160,'packet','Minute cu Rusia 160'),(13,'eu_usa_min_70',15,70,'packet','Minute cu Europa şi SUA 70'),(14,'eu_usa_min_125',30,125,'packet','Minute cu Europa şi SUA 125'),(15,'eu_usa_min_165',45,165,'packet','Minute cu Europa şi SUA 165'),(16,'mix 50 national_min',140,50,'packet','Mix 50'),(17,'mix 50 mob_min',35,50,'packet','Mix 50'),(18,'mix 50 rus_min',15,50,'packet','Mix 50'),(19,'mix 50 eu_usa_min',10,50,'packet','Mix 50'),(20,'mix 100 national_min',320,100,'packet','Mix 100'),(21,'mix 100 mob_min',75,100,'packet','Mix 100'),(22,'mix 100 rus_min',30,100,'packet','Mix 100'),(23,'mix 100 eu_usa_min',20,100,'packet','Mix 100'),(24,'mix 150 national_min',550,150,'packet','Mix 150'),(25,'mix 150 mob_min',120,150,'packet','Mix 150'),(26,'mix 150 rus_min',50,150,'packet','Mix 150'),(27,'mix 150 eu_usa_min',35,150,'packet','Mix 150'),(28,'st',300,24,'plan','Standard'),(29,'ec',200,6,'plan','Econom'),(30,'eu_usa_min add',1,2.5,'adding',NULL),(31,'st add',1,0.096,'adding',NULL),(32,'ec add',1,0.24,'adding',NULL),(33,'mob_min add',1,1.8,'adding',NULL),(34,'rus_min add',1,1.5,'adding',NULL);
