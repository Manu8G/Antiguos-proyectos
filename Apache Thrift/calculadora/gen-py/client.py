from calculadora import Calculadora

from thrift import Thrift
from thrift.transport import TSocket
from thrift.transport import TTransport
from thrift.protocol import TBinaryProtocol

transport = TSocket.TSocket("localhost", 9090)
transport = TTransport.TBufferedTransport(transport)
protocol = TBinaryProtocol.TBinaryProtocol(transport)

client = Calculadora.Client(protocol)

transport.open()

print("hacemos ping al server")
client.ping()

operando = input("Introduzca el tipo de operacion a realizar (suma == +, resta == -, multiplicacion == *, division == /, raiz == S (Raiz, primero el exponente de la raiz), logaritmo == L y factorial == F): ")
operandos = ['+', '-', '*', '/', 'S', 'L', 'F']

while operando not in operandos:
    print("Las opciones validas son +, -, *, /, S (Raiz, primero el exponente de la raiz), L (logaritmo neperiano) y F (factorial) se lo vuelvo a repetir:")
    operando = input("Introduzca el tipo de operacion a realizar (suma == +, resta == -, multiplicacion == *, division == /, raiz == S (Raiz, primero el exponente de la raiz), logaritmo == L y factorial == F): ")

num1 = float(input("Introduzca el primer numero: "))

if operando != 'F' and operando != 'L':
    num2 = float(input("Introduzca el segundo numero: "))

if operando == '+':
    result = client.suma(num1, num2)
    print("{} + {} = {}".format(num1, num2, result))

elif operando == '-':
    result = client.resta(num1, num2)
    print("{} - {} = {}".format(num1, num2, result))

elif operando == '*':
    result = client.multiplicacion(num1, num2)
    print("{} * {} = {}".format(num1, num2, result))

elif operando == '/':
    result = client.division(num1, num2)
    print("{} / {} = {}".format(num1, num2, result))

elif operando == 'S':
    result = client.raiz(num1, num2)
    print("{} RAIZ {} = {}".format(num1, num2, result))

elif operando == 'L':
    result = client.logaritmo_neperiano(num1)
    print("ln({}) = {}".format(num1, result))
    
elif operando == 'F':
    result = client.factorial(num1)
    print("{}! = {}".format(num1, result))


transport.close()
