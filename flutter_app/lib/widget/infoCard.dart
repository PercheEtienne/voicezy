import 'package:flutter/material.dart';

class DataCard extends StatelessWidget {

	final String data;
	final String time;
	final String categorie;

	DataCard({this.data, this.categorie, this.time});

	@override
  Widget build(BuildContext context) {

		String unit;

		String date = time.substring(0,time.indexOf(" "));
		String hour = time.substring(time.indexOf(" ")+1);

		if (categorie == "Humidité")
			unit = "%";
		else if (categorie == "Luminosité")
			unit = " Lux";
		else
			unit = "°C";

    return Container(
			width: MediaQuery.of(context).size.width,
			height: 130,
			child: Stack(
				children: <Widget>[
					Container(
						margin: EdgeInsets.only(right: 50),
					  child: Padding(
					    padding: const EdgeInsets.only(top:8.0),
					    child: Center(
					    	child: Text(
					    		data + unit,
					    		style: TextStyle(
					    			color: Colors.black,
					    			fontSize: 28,
					    			fontWeight: FontWeight.bold
					    		),
					    	),
					    ),
					  ),
					),
					Positioned(
						right: 40,
						top : 40,
						height: 62,
						child: Column(
							mainAxisAlignment: MainAxisAlignment.spaceBetween,
							crossAxisAlignment: CrossAxisAlignment.start,
							children: <Widget>[
								Row(
									children: <Widget>[
										Icon(Icons.date_range, color: Color(0xffC72A2A)),
										Padding(
										  padding: const EdgeInsets.only(left:8.0),
										  child: Text(date),
										)
									],
								),
								Row(
									children: <Widget>[
										Icon(Icons.timer, color: Color(0xff0A84C9),),
										Padding(
										  padding: const EdgeInsets.only(left:8.0),
										  child: Text(hour),
										)
									],
								),
							],
						),
					)
				],
			),
			decoration: BoxDecoration(
				image: DecorationImage(
					image: categorie=="Humidité"? AssetImage("assets/humidity.png") : categorie=="Température"? AssetImage("assets/temp outdoor.png") : categorie=="Luminosité"? AssetImage("assets/luminosity.png") :  AssetImage("assets/temp indoor.png"),
					fit: BoxFit.cover
				)
			),
		);
  }
}
