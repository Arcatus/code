import persistqueue
from persistqueue import FIFOSQLiteQueue

directory = '/home/carlos/Documentos/code/Python/'

def main():
    
    queue = persistqueue.SQLiteQueue(directory+'Queues_app/'+
                get_queue_prin['datos'][0]['datosEquipo']['host'].replace(
                                                    '-','_'), auto_commit=True)

if __name__ == "__main__":
    main()