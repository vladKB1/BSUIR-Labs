using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace DataAccessLayer.Models
{
    public class PurchasingInfo
    {
        public List<ProductVendor> ProductVendors { get; set; }
        public List<PurchaseOrderDetail> PurchaseOrderDetails { get; set; }
        public List<PurchaseOrderHeader> PurchaseOrderHeaders { get; set; }
        public List<ShipMethod> ShipMethods { get; set; }
        public List<Vendor> Vendors { get; set; }

        public PurchasingInfo()
        {
        }

        public PurchasingInfo(List<ProductVendor> productVendors,
                              List<PurchaseOrderDetail> purchaseOrderDetails,
                              List<PurchaseOrderHeader> purchaseOrderHeaders,
                              List<ShipMethod> shipMethods,
                              List<Vendor> vendors)
        {
            ProductVendors = productVendors;
            PurchaseOrderDetails = purchaseOrderDetails;
            PurchaseOrderHeaders = purchaseOrderHeaders;
            ShipMethods = shipMethods;
            Vendors = vendors;
        }
    }
}
