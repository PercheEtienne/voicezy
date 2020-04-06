import 'dart:async';
import 'dart:io' show Platform;

import 'package:beertracker/widget/infoCard.dart';
import 'package:flutter/material.dart';
import 'package:firebase_core/firebase_core.dart';
import 'package:firebase_database/firebase_database.dart';

Future<void> main() async {
	WidgetsFlutterBinding.ensureInitialized();
	final FirebaseApp app = await FirebaseApp.configure(
		name: 'db2',
		options: const FirebaseOptions(
			googleAppID: '1:268326084099:android:eca4a7373e5ecf85477836',
			apiKey: 'AIzaSyBntdufX52MP6D-vTKehA4CXkMelIajnZs',
			databaseURL: 'https://voicezy-48275.firebaseio.com',
		),
	);
	runApp(MaterialApp(
		debugShowCheckedModeBanner: false,
		title: 'Flutter Database Example',
		home: MyHomePage(app: app),
	));
}

class MyHomePage extends StatefulWidget {
	MyHomePage({this.app});
	final FirebaseApp app;

	@override
	_MyHomePageState createState() => _MyHomePageState();
}

class _MyHomePageState extends State<MyHomePage> {

	@override
	Widget build(BuildContext context) {

		var _firebaseRef = FirebaseDatabase().reference().child("users");

		return Scaffold(
			appBar: AppBar(
				title: const Text('Voicezy'),
			),
			body: StreamBuilder(
				stream: _firebaseRef.onValue,
				builder: (context, snap) {

					if (snap.hasData && !snap.hasError && snap.data.snapshot.value != null) {

						Map data = snap.data.snapshot.value;
						List item = [];

						data.forEach((index, data) => item.add({"key": index, ...data}));

						return ListView.builder(
							itemCount: item.length,
							itemBuilder: (context, index) {
								return DataCard(data : item[index]['data'], categorie : item[index]['categorie'], time : item[index]['time']);
							},
						);
					}
					else
						return Text("No data");
				},
			)
		);
	}
}