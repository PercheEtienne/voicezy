import 'package:flutter/material.dart';

class BeerCard extends StatelessWidget {

	final String name;
	final String pourcentage;
	final String imgPath;

	BeerCard({this.name, this.pourcentage, this.imgPath});

	@override
  Widget build(BuildContext context) {
    return Container(
			width: 140,
			child: Stack(
				children: <Widget>[
					Align(
						alignment: Alignment(0, 1),
						child: Padding(
							padding: EdgeInsets.only(bottom: 10),
							child: Container(
								width: 140,
								height: 210,
								decoration: BoxDecoration(
									color: Colors.white,
									borderRadius: BorderRadius.circular(15),
									boxShadow: [
										BoxShadow(
											color: Colors.black12,
											offset: Offset(0, 8),
											blurRadius: 10
										),
									]
								),
							),
						),
					),
					Column(
						mainAxisAlignment: MainAxisAlignment.end,
					  crossAxisAlignment: CrossAxisAlignment.start,
					  children: <Widget>[
					  	Padding(
								padding: EdgeInsets.only(left: 12),
								child: Text(
									pourcentage,
									style: TextStyle(
										color: Colors.black,
										fontWeight: FontWeight.bold,
										fontSize: 18
									),
								),
							),
					    Padding(
					    	padding: EdgeInsets.only(left: 10,bottom: 30),
					      child: Align(
					      	alignment: Alignment.bottomLeft,
					        child: Text(
					        	name,
					        	style: TextStyle(
					        		color: Colors.black,
					        		fontSize: 16
					        	),
					        ),
					      ),
					    ),
					  ],
					),
					Positioned(
						right: 10,
					  top: 0,
					  height: 200,
					  child: Image.network(
					  	imgPath,
					  ),
					),
				],
			),
		);
  }
}
