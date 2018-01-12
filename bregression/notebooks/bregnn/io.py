import pandas as pd


# -------------------------------------------------------------------------------------------
def read_data(fname,columns,**kwargs):

    df = pd.read_hdf(fname,columns=columns,**kwargs)

    return df

    
    
