import glob
import sys

from calculadora import Calculadora
from math import log

from thrift.transport import TSocket
from thrift.transport import TTransport
from thrift.protocol import TBinaryProtocol
from thrift.server import TServer

import logging

logging.basicConfig(level=logging.DEBUG)


class CalculadoraHandler:
    def __init__(self):
        self.log = {}

    def ping(self):
        print("me han hecho ping()")

    def suma(self, n1, n2):
        print("sumando " + str(n1) + " con " + str(n2))
        return n1 + n2

    def resta(self, n1, n2):
        print("restando " + str(n1) + " con " + str(n2))
        return n1 - n2

    def multiplicacion(self, n1, n2):
        print("multiplicando " + str(n1) + " con " + str(n2))
        return n1 * n2

    def division(self, n1, n2):
        print("dividiendo " + str(n1) + " con " + str(n2))
        return n1 / n2

    def raiz(self, n1, n2):
        print("raiz " + str(n1) + " de " + str(n2))
        return n2 ** ( 1.0 / n1 )

    def logaritmo_neperiano(self, n1):
        print("Hacinedo el logarimto neperiano de " + str(n1))
        return log(n1)

    def factorial(self, n1):
        print("Haciendo el factorial de " + str(n1))
        aux = 1.0
        val = int(n1+1)
        for i in range(1, val):
            aux = aux * i
        return aux


if __name__ == "__main__":
    handler = CalculadoraHandler()
    processor = Calculadora.Processor(handler)
    transport = TSocket.TServerSocket(host="127.0.0.1", port=9090)
    tfactory = TTransport.TBufferedTransportFactory()
    pfactory = TBinaryProtocol.TBinaryProtocolFactory()

    server = TServer.TSimpleServer(processor, transport, tfactory, pfactory)

    print("iniciando servidor...")
    server.serve()
    print("fin")
