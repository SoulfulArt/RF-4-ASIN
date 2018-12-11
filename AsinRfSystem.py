import kivy

kivy.require('1.0.5')

from kivy.uix.floatlayout import FloatLayout
from kivy.app import App
from kivy.properties import ObjectProperty, StringProperty
from kivy.core.window import Window

#Set background color as white
Window.clearcolor = (1, 1, 1, 1)
Window.fullscreen = 'auto'

#open file
file = open("/opt/lampp/htdocs/data","w") 
r = True
b = True
g = True
y = True

class AsinRfSystem(FloatLayout):

	def sendBlue(self):
		global b
		file = open("/opt/lampp/htdocs/data","w") 

		if(b):
			file.write("b1")
		else:
			file.write("b0")
		b = not b
		file.close()

	def sendGreen(self):
		global g
		file = open("/opt/lampp/htdocs/data","w")

		if(g):
			file.write("g1")
		else:
			file.write("g0")
		g = not g
		file.close()

	def sendRed(self):
		global r

		file = open("/opt/lampp/htdocs/data","w") 
		if(r):
			file.write("r1")
		else:
			file.write("r0")
		r = not r

		file.close()

	def sendYellow(self):
		global y

		file = open("/opt/lampp/htdocs/data","w") 
		if(y):
			file.write("y1")
		else:
			file.write("y0")
		y = not y

		file.close()

class AsinRfSystemApp(App):

	def build(self):
		return AsinRfSystem()

	def on_stop(self):
		file.close()

if __name__ == '__main__':
	AsinRfSystemApp().run()