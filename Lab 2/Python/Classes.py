class TPoint:
    def __init__(self,X,Y,Z,V1,V2,V3):
        self.__x = X
        self.__y = Y
        self.__z = Z
        self.__v1 = V1
        self.__v2 = V2
        self.__v3 = V3
    
    def setX(self,X):
        self.__x = X
    def setY(self,Y):
        self.__y = Y
    def setZ(self,Z):
        self.__z = Z
    def setV1(self,V1):
        self.__v1 = V1
    def setV2(self,V2):
        self.__v2 = V2
    def setV3(self,V3):
        self.__v3 = V3
    
    def set_coordinates(self,X,Y,Z):
        self.__x = X
        self.__y = Y
        self.__z = Z
    def set_coordinates_of_velocity(self,V1,V2,V3):
        self.__v1 = V1
        self.__v2 = V2
        self.__v3 = V3
    
    def getX(self):
        return self.__x
    def getY(self):
        return self.__y
    def getZ(self):
        return self.__z
    def getV1(self):
        return self.__v1
    def getV2(self):
        return self.__v2
    def getV3(self):
        return self.__v3
    
    def change_position(self,time):
        self.__x += self.__v1*time
        self.__y += self.__v2*time
        self.__z += self.__v3*time
    
    def is_first_octant(self):
        return self.__x > 0 and self.__y > 0 and self.__z > 0