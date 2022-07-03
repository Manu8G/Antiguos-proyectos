var http=require("http");
var url=require("url");
var fs=require("fs");
var path=require("path");
var socketio=require("socket.io");
var MongoClient=require('mongodb').MongoClient;
var MongoServer=require('mongodb').Server;
var mimeTypes={ "html": "text/html", "jpeg": "image/jpeg", "jpg": "image/jpeg", "png": "image/png", "js": "text/javascript", "css": "text/css", "swf": "application/x-shockwave-flash"};

var httpServer=http.createServer(
	function(request, response){
		var uri=url.parse(request.url).pathname;
		if(uri=="/") uri="/cliente.html";
		var fname=path.join(process.cwd(), uri);
		fs.exists(fname, function(exists){
			if(exists){
				fs.readFile(fname, function(err, data){
					if(!err){
						var extension = path.extname(fname).split(".")[1];
						var mimeType = mimeTypes[extension];
						response.writeHead(200, mimeType);
						response.write(data);
						response.end();
					}else{
						response.writeHead(200, {"Content-Type": "text/plain"});
						response.write('Error de lectura en el fichero: '+uri);
						response.end();
					}
				});
			}else{
				console.log("Peticion invalida: "+uri);
				response.writeHead(200, {"Content-Type": "text/plain"});
				response.write('404 Not Found\n');
				response.end();
			}
		});
	}
);

var estadoPersiana='Subida';
var estadoAC='Apagado';

MongoClient.connect("mongodb://localhost:27017/", { useUnifiedTopology: true }, function(err, db) {
	httpServer.listen(8080);
	var io=socketio(httpServer);

	var dbo=db.db("BDA");
	dbo.createCollection("sensores", function(err, collection){	
		io.sockets.on('connection',function(client) {

			//Introducir los datos en la base de datos
	    	client.on('poner', function(data){
				collection.insert(data, {safe:true}, function(err, result) {});
				io.sockets.emit('actualizar', "Temperatura: "+data.temperatura+" Luz: "+data.luz+" Fecha: "+data.fecha);
				io.sockets.emit('actualizarTemp', data.temperatura);
				io.sockets.emit('actualizarLuz', data.luz);
				io.sockets.emit('setEstadoPersiana',estadoPersiana);
				io.sockets.emit('setEstadoAC',estadoAC);
			});
		//Luz
			//Modificamos el estado de la persiana
			client.on('updateEstadoPersiana', function(){
				if(estadoPersiana=='Subida'){
					estadoPersiana='Bajada';
				}else{
					estadoPersiana='Subida';
				}
				collection.find().sort({_id:-1}).limit(1).forEach(function(result){
					var d=new Date();
					var tempe=result.temperatura;
					collection.insert({temperatura:tempe, luz:50, fecha:d}, {safe:true}, function(err, result) {});
					io.sockets.emit('actualizar', "Temperatura: "+tempe+" Luz: "+50+" Fecha: "+d);
				});
				io.sockets.emit('setEstadoPersiana',estadoPersiana);
			});

			//Se ha presionado el boton de la persiana y procedemos a modificar su estado
			client.on('usarPersiana', function(){
				setTimeout(()=>{
					if (estadoPersiana=='Subida'){
						estadoPersiana='Bajada';
					}else{
						estadoPersiana='Subida';
					}
					collection.find().sort({_id:-1}).limit(1).forEach(function(result){
						var d = new Date();
						var tempe=result.temperatura;
						collection.insert({temperatura:tempe, luz:50, fecha:d}, {safe:true}, function(err, result) {});
						io.sockets.emit('actualizar', "Temperatura: "+tempe+" Luz: "+50+" Fecha: "+d);
					});
					// Se notifica el nuevo estado a todos los clientes
					io.sockets.emit('setEstadoPersiana',estadoPersiana);
				}, 6000);
			});
			
			//Se activa el mensaje de alerta de la luz
			client.on('luzAlert',function(data){
				io.sockets.emit('updateAlertLuz',data);
			});

		//Temperatura
			//Modificamos el estado del aire acondicionado
			client.on('updateEstadoAC', function(){
				if(estadoAC=='Encendido'){
					estadoAC='Apagado';
				}else{
					estadoAC='Encendido';
				}
				collection.find().sort({_id:-1}).limit(1).forEach(function(result){
					var d=new Date();
					var luces=result.luz;
					collection.insert({temperatura:25, luz:luces, fecha:d}, {safe:true}, function(err, result) {});
					io.sockets.emit('actualizar', "Temperatura: "+25+" Luz: "+luces+" Fecha: "+d);
				});
				io.sockets.emit('setEstadoAC',estadoAC);
			});

			//Se ha presionado el boton del aire acondicionado y procedemos a modificar su estado
			client.on('usarAC', function(){
				setTimeout(()=>{
					if (estadoAC=='Encendido'){
						estadoAC='Apagado';
					}else{
						estadoAC='Encendido';
					}
					collection.find().sort({_id:-1}).limit(1).forEach(function(result){
						var d=new Date();
						var luces=result.luz;
						collection.insert({temperatura:25, luz:luces, fecha:d}, {safe:true}, function(err, result) {});
						io.sockets.emit('actualizar', "Temperatura: "+25+" Luz: "+luces+" Fecha: "+d);
					});
					// Se notifica el nuevo estado a todos los clientes
					io.sockets.emit('setEstadoAC',estadoAC);
				}, 5000);
			});

			//Se activa el mensaje de alerta de la temperatura
			client.on('tempAlert',function(data){
				io.sockets.emit('updateAlertTemp',data);
			});
	    });
    });
});

console.log("Funcionando");
