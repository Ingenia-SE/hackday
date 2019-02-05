import vrep # access all the VREP elements
import time
vrep.simxFinish(-1) # just in case, close all opened connections
clientID=vrep.simxStart('127.0.0.1',19997,True,True,5000,5) # start a connection
if clientID!=-1:
   print ("Connected to remote API server")
   for i in [1,2,3,5,8]:
      [err, target]=vrep.simxGetObjectHandle(clientID, 'Quadricopter_target', vrep.simx_opmode_oneshot_wait)
      vrep.simxSetObjectPosition(clientID, target,-1,[1,1,i],vrep.simx_opmode_streaming)
      time.sleep(0.5)

   for i in [0.5,1,1.5,2,2.5,3,3.5,4,4.5,5,5.5,6]:
      [err, target]=vrep.simxGetObjectHandle(clientID, 'Quadricopter_target', vrep.simx_opmode_oneshot_wait)
      vrep.simxSetObjectPosition(clientID, target,-1,[1-i,1-i,8],vrep.simx_opmode_streaming)
      time.sleep(0.5)
      
   for i in [0.5,1,1.5,2,2.5,3,3.5,4,4.5,5,5.5,6]:
      [err, target]=vrep.simxGetObjectHandle(clientID, 'Quadricopter_target', vrep.simx_opmode_oneshot_wait)
      vrep.simxSetObjectPosition(clientID, target,-1,[-5+i,-5+i,8],vrep.simx_opmode_streaming)
      time.sleep(0.5)

   for i in [8,5,3,2,1]:
      [err, target]=vrep.simxGetObjectHandle(clientID, 'Quadricopter_target', vrep.simx_opmode_oneshot_wait)
      vrep.simxSetObjectPosition(clientID, target,-1,[1,1,i],vrep.simx_opmode_streaming)
      time.sleep(1)
  
   
          

   
else:
   print("Not connected to remote API server")
   sys.exit("Could not connect")




