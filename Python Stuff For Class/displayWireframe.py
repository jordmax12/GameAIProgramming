#!/bin/env python

import Wireframe
import pygame

class ProjectionViewer:
    """ Displays 3D objects on a Pygame screen """

    def __init__(self, width, height):
        self.width = width
        self.height = height
        self.screen = pygame.display.set_mode((width, height))
        pygame.display.set_caption('Wireframe Display')
        self.background = (255, 255, 255)

        self.wireframes = {}
        self.displayNodes = True
        self.displayEdges = True
        self.nodeColour = (255, 0, 0)
        self.edgeColour = (0,0,0)
        self.nodeRadius = 4

    def addWireframe(self, name, wireframe):
        """ Add a named wireframe object. """

        self.wireframes[name] = wireframe

    def run(self):
        """ Create a pygame screen until it is closed. """

        running = True
        while running:
            for event in pygame.event.get():
                if event.type == pygame.QUIT:
                    running = False
                    
            self.display()  
            pygame.display.flip()
        
    def display(self):
        """ Draw the wireframes on the screen. """

        self.screen.fill(self.background)

        for Wireframe in self.wireframes.values():
            if self.displayEdges:
                for edge in Wireframe.edges:
                    pygame.draw.aaline(self.screen, self.edgeColour, (edge.start.x, edge.start.y), (edge.stop.x, edge.stop.y), 1)

            if self.displayNodes:
                for node in Wireframe.nodes:
                    pygame.draw.circle(self.screen, self.nodeColour, (int(node.x), int(node.y)), self.nodeRadius, 0)

if __name__ == '__main__':
    pv = ProjectionViewer(600, 600)

    cube = Wireframe.Wireframe()
    cube.addNodes([(x,y,z) for x in (50,100) for y in (50,50) for z in (150,250)])
    cube.addEdges([(n,n+4) for n in range(0,4)]+[(n,n+1) for n in range(0,8,2)]+[(n,n+2) for n in (0,1,4,5)])
    cube.addNodes([(x,y,z) for x in (100,150) for y in (50,50) for z in (150,250)])
    cube.addEdges([(n,n+8) for n in range(0,5)]+[(n,n+1) for n in range(0,8,2)]+[(n,n+2) for n in (0,1,4,5)])
    
    cube.addNodes([(x,y,z) for x in (150,200) for y in (50,50) for z in (150,250)])
    cube.addEdges([(n,n+16) for n in range(0,5)]+[(n,n+1) for n in range(0,8,2)]+[(n,n+2) for n in (0,1,4,5)])
    cube.addNodes([(x,y,z) for x in (200,250) for y in (50,50) for z in (150,250)])
    cube.addEdges([(n,n+24) for n in range(0,5)]+[(n,n+1) for n in range(0,8,2)]+[(n,n+2) for n in (0,1,4,5)])

    cube.addNodes([(x,y,z) for x in (250,300) for y in (50,50) for z in (150,250)])
    cube.addEdges([(n,n+32) for n in range(0,5)]+[(n,n+1) for n in range(0,8,2)]+[(n,n+2) for n in (0,1,4,5)])
    cube.addNodes([(x,y,z) for x in (300,350) for y in (50,50) for z in (150,250)])
    cube.addEdges([(n,n+40) for n in range(0,5)]+[(n,n+1) for n in range(0,8,2)]+[(n,n+2) for n in (0,1,4,5)])

    cube.addNodes([(x,y,z) for x in (350,400) for y in (50,50) for z in (150,250)])
    cube.addEdges([(n,n+48) for n in range(0,5)]+[(n,n+1) for n in range(0,8,2)]+[(n,n+2) for n in (0,1,4,5)])
    cube.addNodes([(x,y,z) for x in (400,450) for y in (50,50) for z in (150,250)])
    cube.addEdges([(n,n+56) for n in range(0,5)]+[(n,n+1) for n in range(0,8,2)]+[(n,n+2) for n in (0,1,4,5)])

    cube.addNodes([(x,y,z) for x in (450,500) for y in (50,50) for z in (150,250)])
    cube.addEdges([(n,n+64) for n in range(0,5)]+[(n,n+1) for n in range(0,8,2)]+[(n,n+2) for n in (0,1,4,5)])
    cube.addNodes([(x,y,z) for x in (500,550) for y in (50,50) for z in (150,250)])
    cube.addEdges([(n,n+72) for n in range(0,5)]+[(n,n+1) for n in range(0,8,2)]+[(n,n+2) for n in (0,1,4,5)])
    #
    cube.addNodes([(x,y,z) for x in (50,100) for y in (100,100) for z in (150,250)])
    cube.addEdges([(n,n+78) for n in range(0,5)]+[(n,n+1) for n in range(0,8,2)]+[(n,n+2) for n in (0,1,4,5)])
    cube.addEdges([(n,n+80) for n in range(0,5)]+[(n,n+1) for n in range(0,8,2)]+[(n,n+2) for n in (0,1,4,5)])
    cube.addNodes([(x,y,z) for x in (100,150) for y in (100,100) for z in (150,250)])
    cube.addEdges([(n,n+86) for n in range(0,6)]+[(n,n+1) for n in range(0,8,2)]+[(n,n+2) for n in (0,1,4,5)])
    cube.addEdges([(n,n+88) for n in range(0,6)]+[(n,n+1) for n in range(0,8,2)]+[(n,n+2) for n in (0,1,4,5)])
    
    cube.addNodes([(x,y,z) for x in (150,200) for y in (100,100) for z in (150,250)])

    pv.addWireframe('cube', cube)
    pv.run()
