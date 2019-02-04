import vrep
import sys

vrep.simxFinish(-1)
clientID = vrep.simxStart('127.0.0.1', 20000, True, True, 5000, 5)
vrep.simxSynchronous(clientID, True)

if clientID != -1:

    print('Connected with VREP')
    print("")

    r, target = vrep.simxGetObjectHandle(clientID, 'Quadricopter_target', vrep.simx_opmode_oneshot_wait)

    while (vrep.simxGetConnectionId(clientID)) == 1:
        x = float(input("Dame x:  "))
        y = float(input("Dame y:  "))
        z = float(input("Dame z:  "))
        print("")
        vrep.simxSetObjectPosition(clientID, target, -1, [x,y,z], vrep.simx_opmode_oneshot)




else:
    sys.exit('Error: unable to connect')
    vrep.simxFinish(clientID)
