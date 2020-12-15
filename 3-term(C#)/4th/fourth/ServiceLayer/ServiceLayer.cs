using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using DataAccessLayer.Models;

namespace ServiceLayer
{
    public class ServiceLayer
    {
        public DataAccessLayer.DataAccessLayer DAL;

        public ServiceLayer(DataAccessLayer.DataBaseOptions.ConnectionOptions options)
        {
            DAL = new DataAccessLayer.DataAccessLayer(options);
        }

        public PurchasingInfo GetPurchasingInfo()
        {
            List<ProductVendor> productVendors = 
                DAL.GetListItems<ProductVendor>("GetProductVendors");
            List<PurchaseOrderDetail> purchaseOrderDetails = 
                DAL.GetListItems<PurchaseOrderDetail>("GetPurchaseOrderDetails");
            List<PurchaseOrderHeader> purchaseOrderHeaders = 
                DAL.GetListItems<PurchaseOrderHeader>("GetPurchaseOrderHeaders");
            List<ShipMethod> shipMethods = DAL.GetListItems<ShipMethod>("GetShipMethods");
            List<Vendor> vendors = DAL.GetListItems<Vendor>("GetVendors");
            
            return new PurchasingInfo(productVendors, purchaseOrderDetails,
                purchaseOrderHeaders, shipMethods, vendors);
        }
    }
}
